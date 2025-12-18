#include <list>
#include <string>
#include <vector>
#include "../gclist/gclist.h"
#include "../persons/persons.h"
#include "../catalog/catalog.h"
#include "../stage/stage.h"

GCList :: GCList(CyclistCatalog &catalog){

    std::vector<Cyclist> &cyclists = catalog.Data();

    for (auto &c : cyclists) {
        
        GCEntry entry;
        entry.cyclist = &c;
        entry.delay = 0;
        gc_.push_back(entry);
    }
}

bool OrdenarGCEntry(const GCEntry  &a, const GCEntry &b){

    return a.delay < b.delay;

}

void GCList :: ApplyStage(Stage &Stage){

    auto delays = Stage.GetDelays();

    for(auto &as : gc_){
        
        std::string id = as.cyclist->GetCyclistId();

        if(delays.find(id) != delays.end()){

            as.delay += delays[id]; 
        }
    }

    gc_.sort(OrdenarGCEntry); //ordenamos la lista de ciclistas por delay > a <
}

int GCList::Size(){
    return gc_.size();
}

const std :: list<GCEntry> GCList::GetClassification() const{
    return gc_;
}

std::string GCList :: GetClassification(int size){
    std::string classification;

    int c = 0;
    for(auto gc : gc_){

        if(c >= size){
            break;
        }

        classification += std::to_string(c+1) + ", " + gc.cyclist->GetName() + ", " + std::to_string(gc.delay) + "s\n";
        c++;
    }

    return classification;
}

void GCList :: NormalizeDelays(){

    if(gc_.empty()){
        return;
    }

    int first = gc_.front().delay; //Primer ciclista en la lsita ordenada

    for(auto &entry :gc_){  
        entry.delay -= first;
    }
}
