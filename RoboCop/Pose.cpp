#include "Pose.h"

//! operator functions
bool Pose::operator==(const Pose& other) const {
	return x == other.x && y == other.y && th == other.th;
}

Pose Pose::operator+(const Pose& other) const {
	return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) const {
	return Pose(x - other.x, y - other.y, th - other.th);
}

Pose& Pose::operator+=(const Pose& other) {
	x += other.x;
	y += other.y;
	th += other.th;
	return *this;
}

Pose& Pose::operator-=(const Pose& other) {
	x -= other.x;
	y -= other.y;
	th -= other.th;
	return *this;
}

bool Pose::operator<(const Pose& other) const {
	return x < other.x || (x == other.x && (y < other.y || (y == other.y && th < other.th)));
}

//! member functions
void Pose::getPose(double& _x, double& _y, double& _th) const {
	_x = x;
	_y = y;
	_th = th;
}

void Pose::setPose(double _x, double _y, double _th) {
	x = _x;
	y = _y;
	th = _th;
}

double Pose::findDistanceTo(const Pose& pos) const {
	double dx = x - pos.x;
	double dy = y - pos.y;
	return std::sqrt(dx * dx + dy * dy);
}

double Pose::findAngleTo(const Pose& pos) const {
	double dx = pos.x - x;
	double dy = pos.y - y;
	double radian=atan2(dy, dx);
	return radian * 180 / 3.14159265358979323846264338327950288314159265358979323846264338327950288;
}