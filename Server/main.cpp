#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "server.h"

using namespace std;

int main(int argc, char *argv[])
{
   srand (time(NULL));
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
   /* const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);*/
    //server test;
    vector<int> shuffled;
    int i = 0 ;
    while(shuffled.size()!= 64)
    {
        int numb = rand()%64 + 1;
        if( find(shuffled.begin(), shuffled.end(), numb) == shuffled.end())
            shuffled.push_back(numb);
        i++;
    }
    for (unsigned i = 0; i < shuffled.size(); i++)
    {
            cout << shuffled.at(i) << ' ';
    }
    cout << endl << shuffled.size() << endl;
    int arr[63] = {0};
    for(unsigned i = 0; i < shuffled.size(); i++)
    {
        arr[shuffled.at(i)-1]++;
    }
    bool correct = true;
    for (int i = 0; i < 64; i++)
    {
            if(arr[i] == 0)
            {
                correct = false;
                break;
            }
    }
    if(correct)
        cout << "Correct" << endl;
    else
        cout << "Gone" << endl;
    return app.exec();
}
