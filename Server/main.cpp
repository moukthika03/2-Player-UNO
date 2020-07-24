#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "server.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
   srand (time(NULL));
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    server ser;

   return app.exec();
}
