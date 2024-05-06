#ifndef TESTSTABLEVIEWMODEL_H
#define TESTSTABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include "testwindowmodel.h"

class TestsTableViewModel : public QAbstractTableModel
{
    const QVector<TestModel*> &tests;

public:
    explicit TestsTableViewModel(const QVector<TestModel*> &tests, QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void testsDataUpdated();

};

#endif // TESTSTABLEVIEWMODEL_H
