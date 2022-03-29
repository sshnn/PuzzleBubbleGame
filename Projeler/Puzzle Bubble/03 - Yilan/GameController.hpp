#pragma once
#include "Circle.hpp"



class GameController : public Drawable
{
public:
	GameController(float r);
	void addCircle();
	// Inherited via Cizilebilir
	virtual void draw(Window& window) override;
	void collision(); // çarpýþma testi
	void circleCollision(); // toplarcarpýyormu
	void y_limit();
	void x_limit();
	void throwCircle(float degree);
	void controller();
	int	 getDistance(float x1, float x2, float y1, float y2);
	void lowPos(float y);
	void randomCircles(float = 0);
	float set_degree(float);

	template<typename Container>
	void destroy(Container &c, int idx) 
	{
		c.erase(c.begin() + idx);
	}


	void destroy_if(); // asýlý kaldýysa
	

	circleList	m_circles; // circel list
	
	float		m_r;
	float		m_speed;
	float		m_direct_degree;
	static float m_degree;
	

	//std::shared_ptr<Izgara> m_izgara;
	static std::vector<sf::Vector2f> m_posVec;
	static std::vector<sf::Color> m_colorVec;
	

};

typedef std::shared_ptr<GameController> bubblePtr;
