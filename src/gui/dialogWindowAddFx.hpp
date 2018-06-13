/*
 * dialogWindowAddFx.hpp
 *
 *  Created on: 21 kwi 2018
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

#ifndef DIALOGWINDOWADDFX_HPP_
#define DIALOGWINDOWADDFX_HPP_

#include "config.hpp"

#include "fxGtkList.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include <gtkmm.h>

class AvaibleFxGtkList : public Gtk::TreeView{
public:
	AvaibleFxGtkList();
	virtual ~AvaibleFxGtkList();

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

class DialogWindowAddFx: Gtk::Window{
public:
	DialogWindowAddFx(int argc, char * argv[]);
	void showDialog();
	void hideDialog();
	void markButton(int btnToMark);

	AvaibleFxGtkList *avaibleFxGtkList;

private:
	Gtk::Widget *setWidget();
	Gtk::Frame *title;
};

#endif /* DIALOGWINDOWADDFX_HPP_ */
