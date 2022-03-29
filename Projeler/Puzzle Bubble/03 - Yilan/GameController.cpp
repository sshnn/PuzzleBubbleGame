#include "GameController.hpp"
#include "Frame.hpp"
#include "Direction.hpp"
#include <iostream> // test

GameController::GameController(float r) : m_r{r}, m_speed{r / 2}
{
	
	circlePtr newCircle = Circle::makeCircle(r);
	//yeniDaire->m_pos = sf::Vector2f({ 270,0 });
	m_circles.push_back(newCircle);
	m_isFinish = false;

}

float GameController::m_degree{};
std::vector<sf::Vector2f> GameController::m_posVec{};
std::vector<sf::Color> GameController::m_colorVec{};

void GameController::randomCircles(float f )
{
	/*dairePtr yeniDaire = Circle::daireUret(m_r);
	yeniDaire->m_konum = sf::Vector2f({ 100,0 });
	m_daireler.push_back(yeniDaire);
	
	
	m_daireler.push_back(yeniDaire);
	m_colorVec.push_back(yeniDaire->m_color);
	m_konumVec.push_back(yeniDaire->m_konum);*/
}

float GameController::set_degree(float degree)
{
	m_direct_degree = degree;
	return m_direct_degree;
}






void GameController::addCircle()
{
	
	auto newCircle = Circle::makeCircle(m_r);
	newCircle->m_speed = m_speed;
	newCircle->m_r = m_r;
	m_circles.push_back(newCircle);

	

}




void GameController::controller()
{
	if (m_circles.size() > 2) {
		for (int i = 0; i < m_colorVec.size() - 1 ; ++i) {
			for (int k = 0; k < m_colorVec.size() - 1 ; ++k) {
				if (i == k)
					break;

				if ((m_colorVec.back() == m_colorVec[i] && m_colorVec.back() == m_colorVec[k]) &&
					(getDistance(m_posVec.back().x, m_posVec[i].x, m_posVec.back().y, m_posVec[i].y) <= 65.f) && (getDistance(m_posVec[i].x, m_posVec[k].x, m_posVec[i].y, m_posVec[k].y) <= 65.f))
				{

					destroy(m_circles, i);
					destroy(m_colorVec, i);
					destroy(m_posVec, i);

					destroy(m_circles, k);
					destroy(m_colorVec, k);
					destroy(m_posVec, k);


					// last item
					if (m_posVec.size() == 1)
					{
						m_isFinish = true;
						return;
					}
					destroy(m_circles, m_circles.size() - 2);
					destroy(m_colorVec, m_colorVec.size() - 1);
					destroy(m_posVec, m_posVec.size() - 1);
					
					break;
									
				}
			}
		}
		
	}
}





void GameController::draw(Window& window)
{
	for (auto siradaki : m_circles)
	{
		siradaki->draw(window);
	}
	collision();
	

}

void GameController::collision()
{
	
	y_limit();
	x_limit();
	circleCollision();
	controller();
	
	//destroy_if();

}

void GameController::circleCollision()
{
	if (m_circles.size() > 1) { // 1 den fazla top varsa
		for (int i = 0; i < m_circles.size() - 1; i++) {
			float distance = getDistance(m_circles.back()->m_pos.x, m_circles[i]->m_pos.x, m_circles.back()->m_pos.y, m_circles[i]->m_pos.y);


			if (distance <= 65.f) {
				m_posVec.push_back(m_circles.back()->m_pos);
				m_colorVec.push_back(m_circles.back()->m_color);
				
				m_circles.back()->m_isBumb = true;
				addCircle();	
			}
		}
	}
}

void GameController::y_limit()
{
	if (m_circles.back()->m_pos.y <= Frame::m_limit_y) {
		m_circles.back()->m_pos.y = Frame::m_limit_y;
		m_posVec.push_back(m_circles.back()->m_pos);
		m_colorVec.push_back(m_circles.back()->m_color);

		addCircle();
		m_circles.back()->m_isBumb = true;
	}
}

void GameController::x_limit()
{
	if (m_circles.back()->m_pos.x <= 30 || m_circles.back()->m_pos.x >= 570) {
		m_degree =  180 - 2 * m_direct_degree ;
		// std::cout << m_direct_degree << "\n";
	}
}

void GameController::throwCircle(float degree)
{
	

	if (m_circles.back()->m_isBumb == false) {
		m_circles.back()->throwCircle(degree + m_degree);
	}
}



int GameController::getDistance(float x1, float x2, float y1, float y2)
{
	float square1 = pow((x1 - x2), 2);
	float square2 = pow((y1 - y2), 2);
	float sqrtroot = sqrt(square1 + square2);
	return sqrtroot;
}

void GameController::lowPos(float y)
{
	for (int i = 0; i < m_circles.size() - 1; ++i)
	{
		m_circles[i]->m_pos.y += y;
		m_posVec[i].y += y;
	}
}


void GameController::destroy_if()
{
	

	
	

}




