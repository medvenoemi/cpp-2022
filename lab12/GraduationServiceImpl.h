//
// Created by Noemi on 12/5/2022.
//

#ifndef CPP_2022_GRADUATIONSERVICEIMPL_H
#define CPP_2022_GRADUATIONSERVICEIMPL_H


#include "GraduationService.h"
#include "GraduationDao.h"

class GraduationServiceImpl : public GraduationService {

     GraduationDao *dao;

public:
     GraduationServiceImpl(GraduationDao *dao);

     Student findById(int id) const;
     double getResultByIdAndSubject(int id, const string& subject) const;
};


#endif //CPP_2022_GRADUATIONSERVICEIMPL_H
