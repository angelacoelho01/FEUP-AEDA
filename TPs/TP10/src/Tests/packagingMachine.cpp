#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}


// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned counter = 0;
    for(unsigned i = 0; i < objs.size(); i++){
        if(objs.at(i).getWeight() <= boxCapacity){
            objects.push(objs.at(i));
            objs.erase(objs.begin()+i);
            i--;
            counter++;
        }
    }
    return counter;
}

// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox temp;
    Box box;
    bool inBox = false;
    while(!boxes.empty()) {
        Box top = boxes.top();
        boxes.pop();
        if ((!inBox) && (top.getFree() >= obj.getWeight())) {
            box = top;
            inBox = true;
        }
        else temp.push(top);
    }
    boxes = temp;
    return box;
}

// TODO
unsigned PackagingMachine::packObjects() {
    while(!objects.empty()){
        Object top = objects.top();
        objects.pop();

        Box box = searchBox(top);

        box.addObject(top);
        boxes.push(box);
    }
    return boxes.size();

}

// TODO
string PackagingMachine::printObjectsNotPacked() const {
    stringstream ss;
    if(objects.empty()) ss << "No objects!" << std::endl;
    else {
        HeapObj temp = objects;
        while (!temp.empty()) {
            Object top = temp.top();
            temp.pop();
            ss << top << std::endl;
        }
    }
    return ss.str();
}

// TODO
Box PackagingMachine::boxWithMoreObjects() const {
    if(boxes.empty()) throw MachineWithoutBoxes();
    Box fullerBox = boxes.top();
    HeapBox temp = boxes;
    while(!temp.empty()){
        Box top = temp.top();
        temp.pop();
        if(top.getSize() > fullerBox.getSize()) fullerBox = top;
    }
    return fullerBox;
}