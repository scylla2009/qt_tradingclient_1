/* 
 * File:   GUI.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#ifndef _MktDataGUI_H
#define	_MktDataGUI_H

#include "ui_reqMktDataGUI.h"
#include "PosixClient.h"
#include "MarketData.h"
#include "GUIMarketData.h"
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>


void processMessages();
void endProcessMessages();
void processMessages2();
void processMessages3();

class ReqMktDataGUI : public QDialog {
    Q_OBJECT
public:
    ReqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr);
    virtual ~ReqMktDataGUI();
    static int totalGUIReqActive;
public slots:
    void requestClicked();    
    void cancelClicked();
    void guiRequestClicked();
    void displayData(int tickerId, rec_ptr record_ptr);
    void myTickSizeGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickPriceGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringGUIUpdate(int tickerId, rec_ptr record_ptr);
Q_SIGNALS:
    void newMktData(int tickerId, rec_ptr record_ptr);

private:
    Ui::reqMktDataGUI widget;
    boost::shared_ptr<IB::PosixClient> client;
    
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers;
    std::vector<pMktDataObserver> tickPriceObservers;
    std::vector<pMktDataObserver> tickStringObservers;
    
    void myTickPriceUpdate(int tickerId, rec_ptr record_ptr);
    void myTickSizeUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringUpdate(int tickerId, rec_ptr record_ptr);
    
    void marketDataFeedDelete(void);
    void guiMarketDataFeedDelete(void);
    
    std::vector<IB::Contract> observedContracts;
    std::map<int, boost::shared_ptr<IB::Contract> > guiObservedContracts;
    bool thisGUIReqActive;
};
typedef std::map<int, boost::shared_ptr<IB::Contract> > tickerIdContractMap;
typedef std::vector<boost::shared_ptr<MarketDataObserver> >::iterator vecPmktDataObsIt;

#endif	/* _GUI_H */
