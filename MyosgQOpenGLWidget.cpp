//
// Created by horrs on 2024/3/8.
//

#include "include/MyosgQOpenGLWidget.h"
#include <QMouseEvent>
#include <osgEarth/LogarithmicDepthBuffer>

MyosgQOpenGLWidget::MyosgQOpenGLWidget(QWidget *parent) : osgQOpenGLWidget(parent) {
    setMouseTracking(true);
    setFocus();

    connect(this, &osgQOpenGLWidget::initialized, [=]() {
        // 【非常关键】设置相机的投影矩阵
        QSize size = this->sizeHint();
        float aspectRatio = static_cast<float>(size.width()) / static_cast<float>(size.height());
        this->getOsgViewer()->getCamera()->setProjectionMatrixAsPerspective(30.f, aspectRatio, 1.f, 1000.f);

        // 解决：osgEarth加载shp文件，LineSymbol不显示
        osgEarth::GLUtils::setGlobalDefaults(this->getOsgViewer()->getCamera()->getOrCreateStateSet());

        // 解决：osgearth消除近裁剪平面离物体太近时的裁剪问题
        osgEarth::LogarithmicDepthBuffer buf;
        buf.install(this->getOsgViewer()->getCamera());
    });
}

QSize MyosgQOpenGLWidget::sizeHint() const {
    return QSize(this->width(),this->height());
}

void MyosgQOpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
//    qDebug() << "MyosgQOpenGLWidget::mouseMoveEvent" << "x: " << event->x() << ",y: " << event->y();
    emit signalMouseMoveEvent(event);
    osgQOpenGLWidget::mouseMoveEvent(event);
}
