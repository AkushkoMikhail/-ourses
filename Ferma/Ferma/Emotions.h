#pragma once

#include <string>

/**
 * \����� ���������� �� ������
 */
class Emotions
{
public:
	Emotions(std::string joySound):_joySound(joySound){}

protected:
	virtual void Joy();
	virtual void Sadness();

private:
	std::string _joySound;
};

