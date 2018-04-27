/*
 * dialogWindowMoveFx.hpp
 *
 *  Created on: 27 kwi 2018
 *      Author: SF
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

	ActualFxGtkList *avaibleFxGtkList;

private:
	Gtk::Widget *setWidget();
	Gtk::Frame *title;
};



#endif /* DIALOGWINDOWMOVEFX_HPP_ */
