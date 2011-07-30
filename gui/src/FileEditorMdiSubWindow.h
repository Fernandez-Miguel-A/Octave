/* OctaveGUI - A graphical user interface for Octave
 * Copyright (C) 2011 Jacob Dawid
 * jacob.dawid@googlemail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILEEDITORMDISUBWINDOW_H
#define FILEEDITORMDISUBWINDOW_H

#include <QMdiSubWindow>
#include <QToolBar>
#include <QStatusBar>
#include <QCloseEvent>
#include <Qsci/qsciscintilla.h>
// Not available in the Debian repos yet!
// #include <Qsci/qscilexeroctave.h>
#include "lexer/lexeroctavegui.h"

const char UNNAMED_FILE[]     = "<unnamed>";
const char SAVE_FILE_FILTER[] = "Octave Files  *.m(*.m);;All Files   *.*(*.*)";

class FileEditorMdiSubWindow:public QMdiSubWindow
{
Q_OBJECT public:
  FileEditorMdiSubWindow (QWidget * parent = 0);
  ~FileEditorMdiSubWindow ();
  void loadFile (QString fileName);
  void setEditorLexer (LexerOctaveGui *lexer);

public slots:

  void newFile ();
  void openFile ();
  void saveFile ();
  void saveFile (QString fileName);
  void saveFileAs ();

  void showToolTipNew ();
  void showToolTipOpen ();
  void showToolTipSave ();
  void showToolTipSaveAs ();
  void showToolTipUndo ();
  void showToolTipRedo ();
  void registerModified (bool modified);

protected:
  void closeEvent(QCloseEvent *event);

private:
  int checkFileModified (QString msg);
  void construct ();
  QToolBar *m_toolBar;
  QsciScintilla *m_editor;
  QStatusBar *m_statusBar;
  QString m_fileName;
  bool m_modified;

private slots:
  void handleModificationChanged(bool modified);

};

#endif // FILEEDITORMDISUBWINDOW_H
