//
// Created by horrs on 2024/3/8.
//

#ifndef OSG_STUDY1_MYOSGQOPENGLWIDGET_H
#define OSG_STUDY1_MYOSGQOPENGLWIDGET_H

#include "commonheader.h"

class MyosgQOpenGLWidget : public osgQOpenGLWidget {
    Q_OBJECT
public:
    explicit MyosgQOpenGLWidget(QWidget *parent = nullptr);

public:
    QSize sizeHint() const override;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

signals:

    void signalMouseMoveEvent(QMouseEvent *event);
};

#endif //OSG_STUDY1_MYOSGQOPENGLWIDGET_H
