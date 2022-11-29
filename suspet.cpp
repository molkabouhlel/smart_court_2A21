#include "suspet.h"
#include "stmp.h"
#include "mainwindow.h"
#include <curl/curl.h>

#include<QPrintDialog>
#include<QPrinterInfo>
///#include <CkRest.h>
//#include <CkJsonObject.h>
#include <QString>


Suspet::Suspet()
{
    id=0;
    nom="";
    prenom="";
}

Suspet::Suspet(int a,QString b,QString c,QString d,QDate e,QString f,int g,int h,QString i)
{
    this->id=a;
    this->nom=b;
    this->prenom=c;
    this->adresse=d;
    this->date_naissance=e;
    this->case_id=f;
    this->numero1=g;
    this->numero2=h;
    this->mail=i;

}
bool Suspet::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString n1_string=QString::number(numero1);
    QString n2_string=QString::number(numero2);



    query.prepare("INSERT INTO SUSPET (id, nom,prenom,adresse,date_naissance,case_id,numero1,numero2,mail) "
                  "VALUES (:id, :nom, :prenom ,:adress,:date_naissance,:case_id,:numero1,:numero2,:mail)");
    query.bindValue(":id",id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adress", adresse);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":case_id", case_id);
    query.bindValue(":numero1", n1_string);
    query.bindValue(":numero2", n2_string);
    query.bindValue(":mail", mail);


    return  query.exec();
}
QSqlQueryModel * Suspet::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SUSPET");
    return model;
}
bool Suspet:: supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from SUSPET where id=:id");
    query.bindValue(":id",id);
    return  query.exec();
}
QSqlQueryModel * Suspet::recherche(QString id)/*cherche un producteur de meme id*/
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM SUSPET WHERE ID LIKE '"+id+"'  ");

    return model;
}
bool Suspet::existance(QString id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT * FROM Suspet WHERE id= ?");
    query.addBindValue(id);
    if(query.exec() )
    {
        while (query.next())
        {
            count ++;
        }
        if(count==1)
        {
            msgBox.setText("id deja existe");
            msgBox.exec();
            return 0;
        }

    }
    return 1;
}
QSqlQueryModel * Suspet::trier(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;

    if(test==1)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY DATE_NAISSANCE ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY NOM ASC ") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM SUSPET ORDER BY ID ASC ") ;
    }

    if (query.exec()&&query.next())
    {
        model->setQuery(query) ;
    }
    return model;

}

/*


void ChilkatSample()
    {
    // Demonstrates how to use Basic Authentication in a REST API call for Twilio.
    // Sends an SMS text message..

    // This example requires the Chilkat API to have been previously unlocked.
    // See Global Unlock Sample for sample code.

    CkRest *rest = new CkRest();

    // Use Basic Authentication.
    // Your Twilio Account SID is the username.
    // Your Twilio Auth Token is the password.
    bool success = rest->SetAuthBasic("TWILIO_ACCOUNT_SID","TWILIO_AUTH_TOKEN");

    // Make the initial connection (without sending a request yet) to Twilio.
    bool bTls = true;
    int port = 443;
    bool bAutoReconnect = true;
    success = rest->Connect("api.twilio.com",port,bTls,bAutoReconnect);
    if (success != true) {
        qDebug() << rest->lastErrorText() << "\r\n";
        return;
    }

    // Provide the information for the SMS text message:
    success = rest->AddQueryParam("To","+16518675309");
    success = rest->AddQueryParam("From","+15005550006");
    success = rest->AddQueryParam("Body","Hey Jenny! Good luck on the bar exam!");

    // Send the SMS text message.
    // Your Twilio Account SID is part of the URI path:
    const char *responseJson = rest->fullRequestFormUrlEncoded("POST","/2010-04-01/Accounts/TWILIO_ACCOUNT_SID/Messages.json");
    if (rest->get_LastMethodSuccess() != true) {
        qDebug() << rest->lastErrorText() << "\r\n";
        return;
    }



    // The response is JSON.  We'll show how to get a few bits of information from it.
    // A full sample JSON response is shown below..

    CkJsonObject json;
    json.put_EmitCompact(false);
    success = json.Load(responseJson);

    // First show the entire JSON.
    //qDebug()<< json.emit() << "\r\n";

    // Now get some individual pieces of information:
    qDebug() << "sid: " << json.stringOf("sid") << "\r\n";
    qDebug() << "body: " << json.stringOf("body") << "\r\n";
    qDebug() << "media: " << json.stringOf("subresource_uris.media") << "\r\n";

    qDebug() << "Success." << "\r\n";

    // Sample JSON response:

    // {
    //   "sid": "MM97ecfd43e9f24e99b0c2c6ee016949e3",
    //   "date_created": null,
    //   "date_updated": null,
    //   "date_sent": null,
    //   "account_sid": "112e1111e0151133d11112101111d1111",
    //   "to": "+16518675309",
    //   "from": "+15005550006",
    //   "messaging_service_sid": null,
    //   "body": "Sent from your Twilio trial account - Hey Jenny! Good luck on the bar exam!",
    //   "status": "queued",
    //   "num_segments": "1",
    //   "num_media": "0",
    //   "direction": "outbound-api",
    //   "api_version": "2010-04-01",
    //   "price": null,
    //   "price_unit": "USD",
    //   "error_code": null,
    //   "error_message": null,
    //   "uri": "/2010-04-01/Accounts/AC2e9b6bc0f51133df24926f07341d3824/Messages/MM97ecfd43e9f24e99b0c2c6ee016949e3.json",
    //   "subresource_uris": {
    //     "media": "/2010-04-01/Accounts/AC2e9b6bc0f51133df24926f07341d3824/Messages/MM97ecfd43e9f24e99b0c2c6ee016949e3/Media.json"
    //   }
    // }
    }
*/
