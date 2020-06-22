#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H

#include "statistics.h"

class PlayerStatistics : public Statistics
{
public:
    explicit PlayerStatistics(QObject *parent = nullptr);
};

#endif // PLAYERSTATISTICS_H
