/**
* @author Nihat Deniz Özkan
* @date 29.12.2023
* @brief: This class has the task of keeping and managing the robot's location information
*
* “th” robot indicates its orientation. x and y take values in meters. th is valued in degrees.
*/

#pragma once
#include <cmath>
class Pose
{
private:
	double x;
	double y;
	double th;	
public:

	//! Constructor: Initialize the position with x = 0, y = 0, th =0
	Pose(double x = 0, double y = 0, double th = 0) : x(x), y(y), th(th) {}

	//! Getter functions for x, y, and th coordinates.
	double getX() const { return x; }
	double getY() const { return y; }
	double getTh() const { return th; }

	//! Setter functions for x, y, and th coordinates.
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setTh(double th) { this->th = th; }

	//! Operators for adding and subtracting poses, as well as adding and subtracting poses in-place.
	bool operator==(const Pose& other) const;

	Pose operator+(const Pose& other) const;

	Pose operator-(const Pose& other) const;

	Pose& operator+=(const Pose& other);

	Pose& operator-=(const Pose& other);

	bool operator<(const Pose& other) const;

	//! Functions for getting and setting pose values using references
	void getPose(double& _x, double& _y, double& _th) const;

	void setPose(double _x, double _y, double _th);

	//! Functions for finding the distance and angle to another pose.
	double findDistanceTo(const Pose& pos) const;

	double findAngleTo(const Pose& pos) const;
	
};

