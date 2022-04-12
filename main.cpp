#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <fstream>
#include <iostream>
using namespace std;



QByteArray fileData;
void ReadFromFile(const char* fileName) {

    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    if (!f.exists()){
        qDebug()<<"No exists";
    }
    if (!f.isOpen()){
        qDebug()<<"Error";
    }
    else{
        qDebug()<<"OK";
    }
    fileData = f.readAll();

    f.close();
}

void WriteToFile(const int* ar, int size) {
        ofstream f1;
        f1.open("resulttask1.txt");
        if (!f1.is_open()){
            qDebug()<<"Error";
        }
        else{
            for (int i=0;i<256;i++){
                f1<<i<<"\t"<<char(i)<<"\t"<<ar[i]<<"\n";
            }
        }
}
void task1(const char* fileName) {
    ReadFromFile(fileName);

    int ar[256];
    memset(&ar[0], 0x00, sizeof(int) * 256);

    for (int i = 0; i < fileData.size(); i++) {
        ar[(fileData[i])]++;
    }
   WriteToFile(&ar[0],256);
}


char binNumb[32];
void perevod(int numDecimal) {
    memset(binNumb, 0x00, 32 * sizeof(int));

    for (int i = 0; i < 32; i++) {
        binNumb[32-i-1] = ((numDecimal & (1 << i))) ? 0x31 : 0x30;
    }
}

void task2(int num) {
    perevod(num);
    qDebug() << binNumb;
}








QList<float> getAverStr(int* ar, int rows, int cols) {
    QList<float> averStr;

    for (int i = 0; i < rows; i++) {
        float averStr_temp = 0;
        for (int j = 0; j < cols; j++) {
            averStr_temp += ar[i*cols + j] / (float)cols;
        }
        averStr.push_back(averStr_temp);   
    }
    return averStr;
}

void task5(int* ar, int N, int M) {
    QList<float> b=getAverStr(ar,N,M);
    qDebug()<<b;
}


// примерная конструкция списка для задания номер 6
struct DATA{
    char* info;
};

struct NODE{
    NODE* next;
    NODE* prev;
    DATA* data;
};

class LinkedList{
private:
    NODE* HEAD;
    NODE* TAIL;
    int len;
   public:
     DATA* element(int num){
        if (HEAD==nullptr){
            return nullptr;
        }
        else{
            NODE*temp=HEAD;
            DATA* tempd=temp->data;
            for (int i=1;i<=num;i++){
                if (temp==nullptr){
                    return nullptr;
                }
                DATA* tempd=temp->data;
                temp=temp->next;
            }
            return tempd;
        }

    }
     int get_len(){
         return len;
     }
};

void task6(LinkedList* list){
    ofstream f;
    f.open("resulttask6.txt");
    if (!f.is_open()){
        qDebug()<<"Error";
    }
    else{
        int len1=list->get_len();
        for (int i=1;i<=len1;i++){
            DATA* element=list->element(i);
            f.write((char*)&element,sizeof(element));
        }

    }
    f.close();
}





int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"rus");
    QCoreApplication a(argc, argv);

    task1("text.txt");

    task2(7567);

    int ar[2][4]={{1,2,3,4},{3,4,5,6}};

    task5(*ar,2,4);







    return 0;
}
