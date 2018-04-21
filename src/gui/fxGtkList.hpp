/*
 * fxGtkList.hpp
 *
 *  Created on: 14 kwi 2018
 *      Author: SF
 */

#ifndef FXGTKLIST_HPP_
#define FXGTKLIST_HPP_

#include "config.hpp"
#include <gtkmm.h>

class FxGtkList : public Gtk::TreeView
{
public:
	FxGtkList();
  virtual ~FxGtkList();

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:
	  ModelColumns() { add(idColumn); add(nameColumn);}

	  Gtk::TreeModelColumn<unsigned int> idColumn;
	  Gtk::TreeModelColumn<Glib::ustring> nameColumn;
  };

  ModelColumns columnsModel;
  Glib::RefPtr<Gtk::ListStore> treeModel;
};



#endif /* FXGTKLIST_HPP_ */
