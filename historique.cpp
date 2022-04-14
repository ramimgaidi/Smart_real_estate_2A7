#include "historique.h"

historique::historique()
{

}
void historique:: enregistrer_txt(QString id_finance ,QString type_trans,QString revenance,QString datee)
{
    QFile file ("C:/Users/21655/Desktop/Projetcpp/Atelier_Connexion/hist.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         QString d_info = QDateTime::currentDateTime().toString();
         QString message2=d_info+"\n- id_finance: " +id_finance+ " type_trans: "+type_trans+ " revenance: "+revenance+" date: "+datee  ;"\n";
          //out << "id_finance: " +id_finance+ " type_trans: "+type_trans+ " revenance: "+revenance+" date: "+datee  << "\n";
         out<<message2<<endl;
          out << "id_finance: " +id_finance+ " type_trans: "+type_trans+ " revenance: "+revenance+" date: "+datee  << "\n";
}
QString historique::imprimer_hist()
{
    chaine="";
       QFile file("C:/Users/21655/Desktop/Projetcpp/Atelier_Connexion/hist.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         chaine="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            chaine+=myString+"\n";

      }
      return chaine;
}
