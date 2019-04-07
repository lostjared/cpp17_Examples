#include "filter.hpp"

namespace ac {
    
    // initalize
    FilterObject::FilterObject() : alpha(0) {
        
    }
    
    FilterObject::FilterObject(const std::string &s) : alpha(0), id(s) {
        
    }
    
    FilterObject::FilterObject(const FilterObject &fo) {
        this->operator=(fo);
    }

    FilterObject &FilterObject::operator=(const FilterObject &fo) {
        // copy data
        // collection = fo.collection
        id = fo.id;
        alpha = fo.alpha;
        return *this;
    }
    
    void FilterObject::setID(const std::string &s) {
        id = s;
    }
    
    SelfAlphaBlend::SelfAlphaBlend() : FilterObject("SelfAlphaBlend") {
        
    }
    
    void SelfAlphaBlend::operator()(/*cv::Mat &frame*/) {
        // modify frame
        alpha = 1.0;
        std::cout << "SelfAlphaBlend ...\n";
    }
    
    void SelfAlphaBlend::reset() {
        alpha = 0;
    }
    
    SelfScale::SelfScale() : FilterObject("SelfScale") {
        alpha = 1.0;
    }
    
    void SelfScale::operator()(/*cv::Mat &frame */) {
        std::cout << "in SelfScale ... \n";
    }
    
    void SelfScale::reset() {
        alpha = 0;
    }
        
}
