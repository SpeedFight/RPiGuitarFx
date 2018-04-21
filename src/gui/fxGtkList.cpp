/*
 * fxGtkList.cpp
 *
 *  Created on: 14 kwi 2018
 *      Author: SF
 */

#include "fxGtkList.hpp"

FxGtkList::FxGtkList()
{
  //Create the Tree model:
  treeModel = Gtk::ListStore::create(columnsModel);
  set_model(treeModel);

  //Add the TreeView's view columns:
  append_column("ID", columnsModel.idColumn);
  append_column("Name", columnsModel.nameColumn);

  /*
   * dostep do danych z kolumny
   * path -> 0
   * path -> 0:1  rodzic 0, dziecko 1 itd...
   */
//  auto it = treeModel->get_iter("0");
//  int id = (*it)[columnsModel.idColumn];
//  std::cout << "  Selected ID=" << id << std::endl;
//
//  typedef Gtk::TreeModel::Children type_children; //minimise code length.
//  type_children children = treeModel->children();


  /*
   * select row
   */
//  Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = get_selection();
//  refTreeSelection->select(it);
}

FxGtkList::~FxGtkList()
{
}



