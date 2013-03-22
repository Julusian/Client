#pragma once

#include "../Shared.h"
#include "ui_InspectorMetadataWidget.h"

#include "CasparDevice.h"

#include "Animations/BorderAnimation.h"
#include "Commands/AbstractCommand.h"
#include "Models/LibraryModel.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>

#include <QtGui/QWidget>

class WIDGETS_EXPORT InspectorMetadataWidget : public QWidget, Ui::InspectorMetadataWidget
{
    Q_OBJECT

    public:
        explicit InspectorMetadataWidget(QWidget* parent = 0);

    protected:
        virtual bool eventFilter(QObject* target, QEvent* event);

    private:
        LibraryModel* model;
        BorderAnimation* animation;

        void checkEmptyDevice();
        void blockAllSignals(bool block);

        Q_SLOT void deviceAdded(CasparDevice&);
        Q_SLOT void deviceRemoved();
        Q_SLOT void labelChanged(QString);
        Q_SLOT void deviceNameChanged(QString);
        Q_SLOT void nameChanged(QString);
};
