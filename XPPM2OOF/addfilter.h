// -*- C++ -*-
// $RCSfile: addfilter.h,v $
// $Revision: 1.3 $
// $Author: langer $
// $Date: 2000-09-06 20:11:22 $



/* This software was produced by NIST, an agency of the U.S. government,
 * and by statute is not subject to copyright in the United States.
 * Recipients of this software assume all responsibilities associated
 * with its operation, modification and maintenance. However, to
 * facilitate maintenance we ask that before distributing modifed
 * versions of this software, you first contact the authors at
 * oof_manager@ctcms.nist.gov. 
 */

#ifndef ADDFILTER_H
#define ADDFILTER_H

#include <stdio.h>

class CharString;

FILE *addfilter(const CharString&, FILE*, const char*);

#endif
