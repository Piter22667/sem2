#include "teststableviewmodel.h"


TestsTableViewModel::TestsTableViewModel(const QVector<TestModel*> &tests, QObject *parent)
    : tests(tests)
    ,QAbstractTableModel{parent}
{}

int TestsTableViewModel::rowCount(const QModelIndex &parent) const
{
    return tests.count();
}

int TestsTableViewModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant TestsTableViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(index.row()<0 || index.row() >= tests.count()){
        return QVariant();
    }
    TestModel* testData = tests[index.row()];

    if(role == Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return testData->name;

        case 1:
            return testData->questions.count();

        case 2:
            return testData->minTestScore;

        default:
            return QVariant();
        }
    }
}

void TestsTableViewModel::testsDataUpdated()
{
    beginResetModel();
    endResetModel();
}
