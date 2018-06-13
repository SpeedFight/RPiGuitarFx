/*
 * fxGtkList.cpp
 *
 *  Created on: 14 kwi 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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



