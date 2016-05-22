/** *************************************************************************
                          cometsitem.h  -  K Desktop Planetarium
                             -------------------
    begin                : 16/05/2016
    copyright            : (C) 2016 by Artem Fedoskin
    email                : afedoskin3@gmail.com
 ***************************************************************************/
/** *************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef COMETSITEM_H_
#define COMETSITEM_H_

#include "skyitem.h"

class KSComet;

class CometsItem : public SkyItem {
public:
    CometsItem(QQuickItem* parent = 0);
    /** Adds an object of type KSComet to m_toAdd. In the next call to
     * updatePaintNode() the object of type PointSourceNode will be created and comet
     * will be moved to m_comets. PointSourceNode represents graphically KSComet on SkyMapLite.
     * This function should be called whenever an object of class KSComet is
     * created.
     *
     * @param KSComet that should be displayed on SkyMapLite
     */
    void addComet(KSComet * comet);
    /**
     * @short Sets m_clear to true. On next call to updatePaintNode all child nodes of RootNode will be
     * deleted. Clears m_comets
     */
    void clear();
protected:
    virtual QSGNode* updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData) override;
private:
    bool m_clear;
    QList<KSComet *> m_comets;
    QList<KSComet *> m_toAdd;
};
#endif