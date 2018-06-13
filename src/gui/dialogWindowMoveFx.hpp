/*
 * dialogWindowMoveFx.hpp
 *
 *  Created on: 27 kwi 2018
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

#ifndef DIALOGWINDOWMOVEFX_HPP_
#define DIALOGWINDOWMOVEFX_HPP_

#include "config.hpp"

#include "fxGtkList.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include <gtkmm.h>

class ActualFxGtkList : public Gtk::TreeView{
public:
	ActualFxGtkList();
	virtual ~ActualFxGtkList();

	//Tree model columns:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:
		ModelColumns() {add(nameColumn);}
		Gtk::TreeModelColumn<Glib::ustring> nameColumn;
	};

	ModelColumns columnsModel;
	Glib::RefPtr<Gtk::ListStore> treeModel;
};

class DialogWindowMoveFx: Gtk::Window{
public:
	DialogWindowMoveFx(int argc, char * argv[]);
	void showDialog();
	void hideDialog();
	void markButton(int btnToMark);

	ActualFxGtkList *actualFxGtkList;

private:
	Gtk::Widget *setWidget();
	Gtk::Frame *title;
};



#endif /* DIALOGWINDOWMOVEFX_HPP_ */
