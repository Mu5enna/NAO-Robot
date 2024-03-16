/**
* @author Eren Nusret ÇİZGEÇ
* @date 08.01.2024
* @brief manages the path plan in the form of a linked list.
*
* Path class supposed to manage the path plan in the form of a linked list.
*/
#pragma once
#include <iostream>
#include <vector>
#include "Pose.h"
#include "Node.h"
/**
 * @class Path
 * @brief Represents a path consisting of poses.
 *
 * The Path class is responsible for managing a sequence of poses that represent a path.
 * It provides methods for adding, removing, and inserting poses in the path, as well as
 * accessing and printing the path.
 */
class Path {
private:
    Node* tail; /**< Pointer to the tail node of the path */
    Node* head; /**< Pointer to the head node of the path */
    int number; /**< Number of poses in the path */

public:
    /**
     * @brief Default constructor for the Path class.
     *
     * Initializes the tail and head pointers to nullptr and sets the number of poses to 0.
     */
    Path() : tail(nullptr), head(nullptr), number(0) {}

    /**
     * @brief Get the node at the specified index.
     *
     * @param index The index of the node to retrieve.
     * @return Pointer to the node at the specified index.
     */
    Node* getNode(int index) const;

    /**
     * @brief Add a pose to the end of the path.
     *
     * @param pose The pose to add.
     */
    void addPos(Pose pose);

    /**
     * @brief clear the path.
     */
    void clear();

    /**
     * @brief Print the path.
     */
    void print() const;

    /**
     * @brief Get a reference to the pose at the specified index.
     *
     * @param index The index of the pose to retrieve.
     * @return Reference to the pose at the specified index.
     */
    Pose& operator[](int index);

    /**
     * @brief Get the pose at the specified index.
     *
     * @param index The index of the pose to retrieve.
     * @return The pose at the specified index.
     */
    Pose getPos(int index) const;

    /**
     * @brief Remove the pose at the specified index.
     *
     * @param index The index of the pose to remove.
     * @return True if the pose was successfully removed, false otherwise.
     */
    bool removePos(int index);

    /**
     * @brief Insert a pose at the specified index.
     *
     * @param index The index at which to insert the pose.
     * @param pose The pose to insert.
     * @return True if the pose was successfully inserted, false otherwise.
     */
    bool insertPos(int index, Pose pose);

    /**
     * @brief Overloaded input stream operator for reading a Path object from an input stream.
     *
     * @param in The input stream.
     * @param path The Path object to read into.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(std::istream& in, Path& path);

    /**
     * @brief Overloaded output stream operator for writing a Path object to an output stream.
     *
     * @param out The output stream.
     * @param path The Path object to write.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Path& path);

    /**
     * @brief Get the number of poses in the path.
     *
     * @return The number of poses in the path.
     */
    int getNumber() const { return number; }
};