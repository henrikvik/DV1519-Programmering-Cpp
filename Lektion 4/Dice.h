#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int value;
	int nrOfFaces;
public:
	Dice(int nrOfFaces = 6);
	~Dice();
	void toss();
	int getValue() const;
	int getNrOfFaces() const;
};

#endif