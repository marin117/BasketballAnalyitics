#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H

#include "statistics.h"

class PlayerStatistics : public Statistics
{
    Q_OBJECT
public:
    explicit PlayerStatistics(QObject *parent = nullptr);

};

#endif // PLAYERSTATISTICS_H
