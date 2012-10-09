
class Game
{
public:
	bool run(void);

protected:
	bool getInput(char *c);
	void timerUpdate(void);

private:
		double frameCount;
		double startTime;
		double lastTime;
};

