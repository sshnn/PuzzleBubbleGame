#pragma once
#include "Circle.hpp"



class GameController : public Drawable
{
public:
	GameController(float r);
	virtual void draw(Window& window) override;
	void addCircle();
	void collision(); // çarpýþma testi
	void circleCollision(); // toplar carpýyor mu
	void y_limit();
	void x_limit();
	void throwCircle(float degree);
	void controller();
	int	 getDistance(float x1, float x2, float y1, float y2);
	void lowPos(float y);
	float set_degree(float);

	template<typename Container>
	void destroy(Container &c, int idx) 
	{
		c.erase(c.begin() + idx);
	}



	circleList	m_circles; // circel list
	float		m_r;
	float		m_speed;
	float		m_direct_degree;
	bool		m_isFinish;
	static float m_degree;
	
	static std::vector<sf::Vector2f> m_posVec;
	static std::vector<sf::Color> m_colorVec;
	

};

using bubblePtr = std::shared_ptr<GameController>;
