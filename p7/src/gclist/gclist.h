#ifndef GCLIST_H
#define GCLIST_H

#include <list>
#include <vector>
#include <map>
#include <string>

#include "../stage/stage.h"
#include "../catalog/catalog.h"
#include "../persons/persons.h"

struct GCEntry{

    Cyclist *cyclist;
    int delay;

};

class GCList{

    private:

        std::list <GCEntry> gc_;

    public:

        GCList(CyclistCatalog &catalog);

        void ApplyStage(Stage &Stage);
        int Size();
        std::string GetClassification(int size);
        const std::list<GCEntry> GetClassification() const;

        void NormalizeDelays();
};

bool OrdenarGCEntry(const GCEntry &a, const GCEntry &b);

#endif