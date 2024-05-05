#ifndef TWOBUTTONSMODELINTERFACE_H
#define TWOBUTTONSMODELINTERFACE_H



class TwoButtonsModelInterface{
public:
    virtual QString getFirstButtonTitle() = 0;
    virtual QString getSecondButtonTitle() = 0;
    virtual ~TwoButtonsModelInterface(){}
};


#endif // TWOBUTTONSMODELINTERFACE_H

