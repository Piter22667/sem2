#include "teststableviewmodel.h"


TestsTableViewModel::TestsTableViewModel(QObject *parent)
    : QAbstractTableModel{parent}
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
    return QVariant();
}

void TestsTableViewModel::testsDataUpdated( QVector<TestModel*> tests)
{
    beginResetModel();
    this->tests = tests;
    endResetModel();
}

QVariant TestsTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if(role == Qt::DisplayRole){
        switch (section){
        case 0:
            return "Test Name";

        case 1:
            return "Question number";

        case 2:
            return "Min test score";

        default:
            return QVariant();
        }
    }
    return QVariant();
}
