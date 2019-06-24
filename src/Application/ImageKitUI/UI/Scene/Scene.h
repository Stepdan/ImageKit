#pragma once

#include <memory>

#include <QGraphicsView>
#include <QGraphicsScene>

namespace ImageKit {

class Scene : public QGraphicsView
{
	Q_OBJECT

public:
	explicit Scene(QWidget *parent = 0);
	~Scene();

public:
	void wheelEvent(QWheelEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;

public:
	void SetImage(const QImage& image);

private:
	std::unique_ptr<QGraphicsScene> m_scene;
};

}
