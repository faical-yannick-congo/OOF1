// -*- C++ -*-
// $RCSfile: griffith_element.h,v $
// $Revision: 1.5 $
// $Author: langer $
// $Date: 2004-10-19 02:24:35 $


/* This software was produced by NIST, an agency of the U.S. government,
 * and by statute is not subject to copyright in the United States.
 * Recipients of this software assume all responsibilities associated
 * with its operation, modification and maintenance. However, to
 * facilitate maintenance we ask that before distributing modifed
 * versions of this software, you first contact the authors at
 * oof_manager@ctcms.nist.gov. 
 */

/* Griffith element */

#ifndef GRIFFITHELEMENT_H
#define GRIFFITHELEMENT_H

class GriffithElement;
class GriffithElement2;

#include "genelement.h"
#include "mutableelement.h"

class GriffithElement : public GTElement, public MutableElement {
protected:
  double young, poisson, t_coeff, knockdown1, knockdown2, gamma;
  static double young_dflt, poisson_dflt, t_coeff_dflt,
    knockdown1_dflt, knockdown2_dflt, gamma_dflt;
#ifdef THERMAL
  double kappa;
  static double kappa_dflt;
#endif // THERMAL
  static Element *binaryread(FILE*, TrueFalse&);
  static ElementTypeRegistration reg;
  static CharString nameplate;
  virtual bool same_type(const Element*) const;
  Cijkl virgin_cijkl() const;
public:
  GriffithElement() {}
  GriffithElement(Grid*);
  static int Nnodes;
  virtual const CharString &tag() const { return nameplate; }

  static void AddArgs(CommandM *cmd) {
    GTElement::AddArgs(cmd);
    AddArgument(cmd, "young", young_dflt);
    AddArgument(cmd, "poisson", poisson_dflt);
    AddArgument(cmd, "alpha", t_coeff_dflt);
#ifdef THERMAL
    AddArgument(cmd, "kappa", kappa_dflt);
#endif // THERMAL
    AddArgument(cmd, "gamma", gamma_dflt);
    AddArgument(cmd, "knockdown1", knockdown1_dflt);
    AddArgument(cmd, "knockdown2", knockdown2_dflt);
    MutableElement::AddArgs(cmd);
  }
  
  virtual void binarywrite(FILE*, char) const;
  virtual std::vector<CharString> *print_properties(ostream &) const;
  virtual CharString parameters() const;

  virtual Cijkl setCijkl() const;
  virtual SymmMatrix setAlpha() const;
#ifdef THERMAL
  virtual Kij setKij() const;
#endif // THERMAL

  virtual int mutate();
  virtual void revert();

  friend class Debug;
};

class GriffithElement2 : public GriffithElement {
  static Element *binaryread(FILE*, TrueFalse&);
  static ElementTypeRegistration reg;
  static CharString nameplate;
public:
  GriffithElement2() {}
  GriffithElement2(Grid *g) : GriffithElement(g) {}
  virtual const CharString &tag() const { return nameplate; }
  virtual int mutate();
};


#endif
