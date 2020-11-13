#include "Warehouse.h"

Warehouse::Warehouse()  {
}

queue<ThinTallBox> Warehouse::getBoxes() {
	return boxes;
}

queue<Object> Warehouse::getObjects() {
    return objects;
}

void Warehouse::setBoxes(queue<ThinTallBox> q) {
    while (!q.empty()) {
        boxes.push(q.front());
        q.pop();
    }
}

void Warehouse::addObject(Object o1) {
    objects.push(o1);
}

int Warehouse::InsertObjectsInQueue(vector <Object> obj){
    std::sort(obj.begin(), obj.end());
    for(const auto & o : obj)
        objects.push(o);
    return obj.size();
}

Object Warehouse::RemoveObjectQueue(int maxSize) {
    queue<Object> objectsUpdated;
    bool foundAlready = false;
    Object objectRemoved;
    while(!objects.empty()){
        if(objects.front().getSize() <= maxSize && !foundAlready){
            foundAlready = true;
            objectRemoved = objects.front();
            objects.pop();
        }
        if(!objects.empty()) {
            objectsUpdated.push(objects.front());
            objects.pop();
        }
    }
    objects = objectsUpdated;
    if(!foundAlready) return Object("dummy", maxSize);
    return objectRemoved;
}

int Warehouse::addPackOfBoxes(vector <ThinTallBox> boV) {
    for(const auto & box : boV)
        boxes.push(box);
    return boxes.size();
}

vector<ThinTallBox> Warehouse::DailyProcessBoxes(){
    vector<ThinTallBox> sentBoxes;
    unsigned int numBoxes = boxes.size();
    while(numBoxes != 0){
        ThinTallBox box = boxes.front();
        //Just sends the box
        if(box.getContentSize() == box.getCapacity()){
            boxes.pop();
            sentBoxes.push_back(box);
        }
        //Processes and then sends the box
        else if(box.getDays() == 0){
            Object addObject = RemoveObjectQueue(box.getCapacity() - box.getContentSize());
            if(addObject.getName() == "dummy") addObject.setSize(0);
            box.insert(addObject);

            boxes.pop();
            sentBoxes.push_back(box);
        }
        //Processes box, update it's time and sends it to the back of the queue
        else{
            Object addObject = RemoveObjectQueue(box.getCapacity() - box.getContentSize());
            if(addObject.getName() == "dummy") addObject.setSize(0);
            box.insert(addObject);

            boxes.pop();
            box.setDaysToSend(box.getDays()-1);
            boxes.push(box);
        }
        numBoxes--;
    }
    return sentBoxes;
}

