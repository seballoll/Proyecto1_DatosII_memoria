#ifndef SET_GET_H
#define SET_GET_H

#include <QSharedDataPointer>
#include <QString>

class Set_GetData : public QSharedData{
    public:
    Set_GetData() : points(-1) {}
    Set_GetData(const Set_GetData &other)
        : QSharedData (other), points(other.points), name(other.name){}
        ~Set_GetData()  {};
        int points;
        QString name;

};

class Set_Get
{
public:
    Set_Get() { data = new Set_GetData; }
    Set_Get(int points,const QString &name ){
        data = new Set_GetData;
        setPoints(points);
        setName(name);
    }
    Set_Get(const Set_Get &other)
        : data (other.data){

    }
    void setPoints(int points) { data->points = points; }
        void setName(const QString &name) { data->name = name; }

        int points() const { return data->points; }
        QString name() const { return data->name; }

private:
    QSharedDataPointer<Set_GetData> data;
};

#endif // SET_GET_H
