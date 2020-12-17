#include "REAgency.h"

#include <algorithm>
#include <stdlib.h>

REAgency::REAgency(): catalogItems(PropertyTypeItem("", "","", 0)) {
	//do nothing!
}

REAgency::REAgency(vector<Property*> properties): catalogItems(PropertyTypeItem("", "","", 0)) {
	this->properties = properties;
}

void REAgency::addProperty(Property* property) {
	this->properties.push_back(property);
}

void REAgency::addProperties(vector<Property*> properties) {
	this->properties = properties;
}

vector<Property*> REAgency::getProperties() const{
	return this->properties;
}

PropertyTypeItem REAgency::getTypeItem(string address, string postalCode, string typology) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getAddress() == address && it.retrieve().getPostalCode() == postalCode && it.retrieve().getTypology() == typology) {
			PropertyTypeItem pti(it.retrieve().getAddress(), it.retrieve().getPostalCode(), it.retrieve().getTypology(), 0);
			pti.setItems(it.retrieve().getItems());
			return pti;
		}
		it.advance();
	}
	return itemNotFound;
}

void REAgency::addTypeItem(Property* property) {
	PropertyTypeItem itemNotFound("", "","", 0);
	PropertyTypeItem pti(property->getAddress(), property->getPostalCode(), property->getTypology(), property->	getPrice());
	PropertyTypeItem ptiX = catalogItems.find(pti);
	if(ptiX == itemNotFound) {
		pti.addItems(property);
		this->catalogItems.insert(pti);
	}
	else {
		this->catalogItems.remove(ptiX);
		ptiX.addItems(property);
		this->catalogItems.insert(ptiX);
	}
	properties.push_back(property);
}

BST<PropertyTypeItem> REAgency::getTypeItems() const {
	return this->catalogItems;
}

vector<ClientRecord> REAgency::getClientRecords() const {
	vector<ClientRecord> records;
	HashTabClientRecord::const_iterator it1 = this->listingRecords.begin();
	HashTabClientRecord::const_iterator it2 = this->listingRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void REAgency::setClientRecords(vector<ClientRecord>& crs) {
	for(unsigned int i = 0; i < crs.size(); i++) {
		listingRecords.insert(crs[i]);
	}

}

priority_queue<Client> REAgency::getClientProfiles() const {
	return clientProfiles;
}
void REAgency::setClientProfiles(priority_queue<Client>& profiles) {
	clientProfiles = profiles;
}

//
// TODO: Part I   - BST
//
void REAgency::generateCatalog() {
	//TODO: A
    for(const auto& property : properties){
        bool found = false;
        PropertyTypeItem propertyT(property->getAddress(), property->getPostalCode()
                                   , property->getTypology(), property->getPrice());
        propertyT.addItems(property);
        BSTItrIn<PropertyTypeItem> it(catalogItems);
        for(it; !it.isAtEnd(); it.advance()){
            PropertyTypeItem* temp = &it.retrieve();
            if(*temp == propertyT){
                temp->addItems(property);
                found = true;
                break;
            }
        }
        if(!found) catalogItems.insert(propertyT);
    }
}

vector<Property*> REAgency::getAvailableProperties(Property* property) const {
	vector<Property*> res;
	//TODO: B
	for(const auto& p : properties){
	    if((get<1>(p->getReservation()) == 0) && (p->getAddress() == property->getAddress()) &&
	    (p->getPostalCode() == property->getPostalCode()) && (p->getTypology() == property->getTypology()))
	        res.push_back(property);
	}
	return res;
}

bool REAgency::reservePropertyFromCatalog(Property* property, Client* client, int percentage) {
	//TODO: C
	float discount = (float)(100 - percentage)/100;
	PropertyTypeItem propertyT(property->getAddress(), property->getPostalCode(),
                                property->getTypology(), property->getPrice());
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	for(; !it.isAtEnd(); it.advance()){
	    PropertyTypeItem temp = it.retrieve();
	    if(temp == propertyT){
            client->addVisiting(property->getAddress(), property->getPostalCode(),
                                property->getTypology(), to_string(property->getPrice() * discount));
	        property->setReservation(make_tuple(client, property->getPrice() * discount));
            catalogItems.remove(temp);
            return true;
	    }
	}
	return false;
}

//
// TODO: Part II  - Hash Table
//
void REAgency::addClientRecord(Client* client) {
	//TODO: D
	listingRecords.insert(ClientRecord(client));
}

void REAgency::deleteClients() {
	//TODO: E
	for(auto it = listingRecords.begin(); it != listingRecords.end(); it++){
	    Client* client = it->getClientPointer();
	    if(client->getVisitedProperties().empty())
	        listingRecords.erase(it);
	}
}

//
// TODO: Part III - Priority Queue
//
void REAgency::addBestClientProfiles(const vector<Client>candidates, int min) {
	//TODO: F
	for(const auto& client : candidates){
	    int numVisited = client.getVisitedProperties().size();
	    int numReserved = 0;
	    //if(client.getVisiting() != emptyTuple) numVisited++;
	    for(const auto& property : properties) {
            if (get<0>(property->getReservation())->getEMail() == client.getEMail())
                numReserved++;
        }
	    if((float)numReserved/numVisited > min) clientProfiles.push(client);
	}

}

vector<Property*> REAgency::suggestProperties() {
	//TODO: G
	vector<Property*> tempProperties;
	priority_queue<Client> temp;
    while(!clientProfiles.empty()){
        Client top = clientProfiles.top();
        clientProfiles.pop();
        if(top.getVisiting() == tuple<string, string, string, string>()) continue;
        int minDiffPostalCode = 99999999;
        Property* suggestedProperty;
        for(const auto& pp : properties){
            int diffPostalCode = abs(stoi(get<1>(top.getVisiting())) - stoi(pp->getPostalCode()));
            if((get<0>(pp->getReservation()) == NULL) && (diffPostalCode < minDiffPostalCode) && (diffPostalCode != 0)) {
                suggestedProperty = pp;
                minDiffPostalCode = diffPostalCode;
            }
        }
        tempProperties.push_back(suggestedProperty);
        temp.push(top);
    }
    clientProfiles = temp;
	return tempProperties;
}
