#pragma once
#include <QWidget>

/**
 * @class AbstractViewModel class
 *
 * An abstract base class that defines 2 basic functions that
 * views must define: resetView() and resetUI()
 */
class View: public QWidget
{
    Q_OBJECT
public:

    explicit View(QWidget* parent = nullptr)
        : QWidget(parent)
    {}
    virtual ~View(){}
    virtual void resetView() = 0;

    /**
     * Resets the UI that corresponds with the given view
     */
    virtual void resetUI() = 0;
};