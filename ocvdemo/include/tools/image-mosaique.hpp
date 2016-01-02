/** @file image-mosaique.hpp
 *  @brief Fen�tre de sortie

    Copyright 2015 J.A. / http://www.tsdconseil.fr

    Project web page: http://www.tsdconseil.fr/log/opencv/demo/index-en.html

    This file is part of OCVDemo.

    OCVDemo is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OCVDemo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with OCVDemo.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef IMAGE_MOSAIQUE_HPP
#define IMAGE_MOSAIQUE_HPP



////////////////////////////////////////////////////////////////////////////
/** @brief Fen�tre afficher un ou plusieurs images
 *  (utilis� pour afficher les r�sultats des traitements)
 *  @todo R��crire � base de fen�tre GTK. */
class ImageMosaique
{
public:
  /** Constructeur */
  ImageMosaique();

  /** Affichage de plusieurs images */
  int show_multiple_images(std::string title,
                           std::vector<cv::Mat> lst,
                           std::vector<std::string> titles);

  /** Mise � jour d'une image en particulier */
  void update_image(int index, const cv::Mat &img);

  void mouse_callback(int event, int x, int y, int flags);

  /** Devrait �tre priv� ! */
  bool callback_init_ok;

  /** Retourne l'image globale */
  cv::Mat get_global_img(){return disp_img;}

private:
  /** Image globale */
  cv::Mat disp_img;

  /** Position de chaque image */
  std::vector<cv::Rect> img_pos;

  /** Dimension de chaque image */
  std::vector<cv::Size> img_sizes;

  utils::Logable journal;

  /** Titre principal */
  std::string title;
};

#endif