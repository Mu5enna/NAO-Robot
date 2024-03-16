/**
* @author Eren Nusret ÇİZGEÇ
* @date 08.01.2024
* @brief: Path test
*/

#include <iostream>
#include "Path.h"
#include "Node.h"

int main() {
    //! Create a Path object
    Path path;

    //! Test addPos() function
    Pose pose1(1.0, 2.0, 3.0);
    path.addPos(pose1);
    Pose pose2(4.0, 5.0, 6.0);
    path.addPos(pose2);

    //! Test print() function
    path.print();

    //! Test operator[] function
    Pose& pose3 = path[0];
    std::cout << "Pose at index 0: " << pose3.getX() << ", " << pose3.getY() << ", " << pose3.getTh() << std::endl;

    //! Test getPos() function
    Pose pose4 = path.getPos(1);
    std::cout << "Pose at index 1: " << pose4.getX() << ", " << pose4.getY() << ", " << pose4.getTh() << std::endl;

    //! Test removePos() function
    path.removePos(0);
    std::cout << "After removing pose at index 0:" << std::endl;
    path.print();

    //! Test insertPos() function
    Pose pose5(7.0, 8.0, 9.0);
    path.insertPos(0, pose5);
    std::cout << "After inserting pose at index 0:" << std::endl;
    path.print();

    return 0;
}
