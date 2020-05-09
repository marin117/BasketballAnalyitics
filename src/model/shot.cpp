#include "shot.h"

Shot::Shot()
{

}

Shot::Shot(const bool &isMiss, const bool &isContested, const bool &isThreePoints, const QPoint& pos) :
    isMiss(isMiss), isContested(isContested), isThreePoints(isThreePoints), pos(pos)
{

}
