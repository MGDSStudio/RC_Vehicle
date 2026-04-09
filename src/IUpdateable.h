//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_IUPDATEABLE_H
#define CMAKESFMLPROJECT_IUPDATEABLE_H


class IUpdateable {
public:
    virtual void update(float tpf);
    virtual void complete();
};


#endif //CMAKESFMLPROJECT_IUPDATEABLE_H
