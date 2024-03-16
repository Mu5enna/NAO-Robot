#include <iostream>
#include "Path.h"
#include "Node.h"

//! Adds a new position to the path.
void Path::addPos(Pose pose) {
    if (head == nullptr) {
        head = new Node{ pose, nullptr, nullptr };
        tail = head;
    }
    else {
        Node* temp = new Node{ pose, tail, nullptr };
        tail->next = temp;
        tail = temp;
    }
    number++;
}


//! Prints the coordinates of each pose in the path.
void Path::print() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->pose.getX() << ", " << temp->pose.getY() << ", " << temp->pose.getTh() << std::endl;
        temp = temp->next;
    }
}

//! Represents a pose in a robotic path.
Pose& Path::operator[](int index) {
    if (index < 0 || index >= number) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = head;
    while (index--) {
        temp = temp->next;
    }
    return temp->pose;
}

//! Retrieves the pose at the specified index in the path.
Pose Path::getPos(int index) const {
    if (index < 0 || index >= number) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = head;
    while (index--) {
        temp = temp->next;
    }
    return temp->pose;
}

//! clears the path
void Path::clear() {
	Node* temp = head;
	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
	head = nullptr;
	tail = nullptr;
	number = 0;
}

//! Removes the element at the specified index from the Path.
bool Path::removePos(int index) {
    if (index < 0 || index >= number) {
        throw std::out_of_range("Index out of range");
    }
    Node* temp = head;
    while (index--) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    else {
        tail = temp->prev;
    }
    delete temp;
    number--;
    return true;
}


//! Inserts a Pose at the specified index in the Path.
bool Path::insertPos(int index, Pose pose) {
    if (index < 0 || index > number) {
        throw std::out_of_range("Index out of range");
    }
    if (index == number) {
        addPos(pose);
    }
    else {
        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }
        Node* newNode = new Node{ pose, temp, temp->next };
        temp->next->prev = newNode;
        temp->next = newNode;
        number++;
    }
    return true;
}
//! Operator functions
std::istream& operator>>(std::istream& is, Pose& pose) {
    double x, y, th;
    is >> x >> y >> th;
    pose.setX(x);
    pose.setY(y);
    pose.setTh(th);
    return is;
}

std::istream& operator>>(std::istream& in, Path& path) {
    int number;
    in >> number;
    for (int i = 0; i < number; i++) {
        Pose pose;
        in >> pose;
        path.addPos(pose);
    }
    return in;
}

std::ostream& operator<<(std::ostream& os, const Pose& pose) {
    os << pose.getX() << ' ' << pose.getY() << ' ' << pose.getTh();
    return os;
}

