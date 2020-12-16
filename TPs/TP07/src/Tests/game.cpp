#include "game.h"
#include <sstream>


//TODO
ostream &operator << (ostream &os, Circle &c1){
	return os << c1.getPoints() << "-" << (c1.getState() ? "true" : "false")<< "-" << c1.getNVisits() << endl;
}


BinaryTree<Circle> Game::createTree(int h, int pos, vector<int> &points, vector<bool> &states){
    int leftPos = 2*pos+1, rightPos = 2*pos+2;
    Circle node(points[pos], states[pos]);
    if(h == 0) return BinaryTree<Circle>(node);
    BinaryTree<Circle> left = createTree(h-1, leftPos, points, states);
    BinaryTree<Circle> right = createTree(h-1, rightPos, points, states);
    return BinaryTree<Circle>(node, left, right);
}


//TODO
Game::Game(int h, vector<int> &points, vector<bool> &states){
    game = createTree(h, 0,points, states);
}


//TODO
string Game::writeGame(){
    BTItrLevel<Circle> it(game);
    ostringstream ss;
	for(; !it.isAtEnd(); it.advance())
	    ss << it.retrieve();
	return ss.str();
}


//TODO
int Game::move(){
    BTItrLevel<Circle> it(game);
    int pos = 1, totalPoints = 0;
    bool end = false;
    if(it.isAtEnd()) return totalPoints;
    while(!end){
        int aux;
        if(it.retrieve().getState()) aux = pos+1;
        else aux = pos;

        it.retrieve().changeState();
        it.retrieve().addNVisits();
        totalPoints = it.retrieve().getPoints();

        for(int i = 0; i < aux && !it.isAtEnd(); i++) it.advance();

        if(!it.isAtEnd()) pos += aux;
        else end = true;
    }
	return totalPoints;
}


//TODO
int Game::mostVisited(){
    int greaterVisits = 0;
    BTItrLevel<Circle> it(game); it.advance();
    for(; !it.isAtEnd(); it.advance())
        if(it.retrieve().getNVisits() > greaterVisits) greaterVisits = it.retrieve().getNVisits();
	return greaterVisits;
}
