#ifndef TESTSTABLEVIEWMODEL_H
#define TESTSTABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include "testwindowmodel.h"

class TestsTableViewModel : public QAbstractTableModel
{
     QVector<TestModel*> tests;

public:
    explicit TestsTableViewModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void testsDataUpdated(QVector<TestModel*> tests);


    // QAbstractItemModel interface
public:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // TESTSTABLEVIEWMODEL_H
