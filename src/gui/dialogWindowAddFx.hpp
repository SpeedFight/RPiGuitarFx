/*
 * dialogWindowAddFx.hpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
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
