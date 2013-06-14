/*
 * Ork: a small object-oriented OpenGL Rendering Kernel.
 * Copyright (c) 2008-2010 INRIA
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _ORK_XML_RESOURCE_LOADER_H_
#define _ORK_XML_RESOURCE_LOADER_H_

#include <map>
#include <vector>
#include "ork/resource/ResourceLoader.h"

namespace ork
{

/**
 * A ResourceLoader that loads ResourceDescriptor from XML files. This loader
 * can load resources from individual XML files, each file containing a single
 * ResourceDescriptor, and from so called XML archive files, each archive file
 * containing one or more ResourceDescriptor. This loader can search for these
 * files in several directories and archives files configured with #addPath and
 * #addArchive.
 *
 * @ingroup resource
 */
class ORK_API XMLResourceLoader : public ResourceLoader
{
public:
    /**
     * Creates a new XMLResourceLoader.
     */
    XMLResourceLoader();

    /**
     * Deletes this XMLResourceLoader.
     */
    virtual ~XMLResourceLoader();

    /**
     * Adds a search path where ResourceDescriptor can be looked for.
     */
    void addPath(const std::string &path);

    /**
     * Adds an XML archive file where ResourceDescriptor can be looked for.
     */
    void addArchive(const std::string &archive);

    /**
     * Returns the path of the resource of the given name.
     *
     * @param name the name of a resource.
     * @return the path of this resource.
     * @throw exception if the resource is not found.
     */
    virtual std::string findResource(const std::string &name);

    /**
     * Loads the ResourceDescriptor of the given name.
     *
     * @param name the name of the ResourceDescriptor to be loaded.
     * @return the ResourceDescriptor of the given name, or NULL if the %resource
     *      is not found.
     */
    virtual ptr<ResourceDescriptor> loadResource(const std::string &name);

    /**
     * Reloads the ResourceDescriptor of the given name.
     *
     * @param name the name of the ResourceDescriptor to be loaded.
     * @param currentValue the current value of this ResourceDescriptor.
     * @return the new value of this ResourceDescriptor, or NULL if this value
     *      has not changed on disk.
     */
    virtual ptr<ResourceDescriptor> reloadResource(const std::string &name, ptr<ResourceDescriptor> currentValue);

protected:
    /**
     * Looks for a file in a set of directories.
     *
     * @param desc the XML part of a ResourceDescriptor.
     * @param paths a set of directory names.
     * @param file a relative file name.
     * @return the absolute file name of the file.
     * @throw exception if the file is not found in any directory.
     */
    virtual std::string findFile(const TiXmlElement *desc, const std::vector<std::string> paths, const std::string &file);

    /**
     * Loads the content of a file.
     *
     * @param file the name of a file.
     * @param[out] size returns the size of the file's content in bytes.
     * @return the file's content.
     */
    virtual unsigned char *loadFile(const std::string &file, unsigned int &size);

    /**
     * Computes the last modification time of the given file.
     *
     * @param name a fie name.
     * @param[out] t returns the last modification time of the given file.
     */
    virtual void getTimeStamp(const std::string &name, time_t &t);

private:
    /**
     * The directories where individual ResourceDescriptor files can be looked for.
     */
    std::vector<std::string> paths;

    /**
     * The archives where other ResourceDescriptor files can be looked for.
     */
    std::vector<std::string> archives;

    /**
     * A cache of the archive files. Maps archive file names to archive content
     * and last modification time on disk.
     */
    std::map<std::string, std::pair<TiXmlDocument*, time_t> > cache;

    /**
     * Returns the XML part of the ResourceDescriptor of the given name. This
     * method looks for this descriptor in the archive files and then, if not
     * found, in the directories specified with #addPath.
     *
     * @param name the name of a ResourceDescriptor.
     * @param[in,out] t the last modification time of this %resource descriptor,
     *      or 0 if it has not been loaded yet. This modification time is
     *      updated by this method if it has changed.
     * @param log true to log an error message if the descriptor is not found.
     * @return the XML part of the ResourceDescriptor of the given name, of NULL
     *      if the last modification time is still equal to t or if the %resource
     *      is not found.
     */
    TiXmlElement *findDescriptor(const std::string &name, time_t &t, bool log = true);

    /**
     * Returns the XML part of the ResourceDescriptor of the given name. This
     * method looks for this descriptor in the given archive file.
     *
     * @param archive the archive file where the descriptor must be looked for.
     * @param name the name of a ResourceDescriptor.
     * @return the XML part of the ResourceDescriptor, or NULL if the archive
     *      file does not contain this %resource descriptor.
     */
    static TiXmlElement *findDescriptor(const TiXmlDocument *archive, const std::string &name);

    /**
     * Builds the XML part of texture %resource descriptors for the special textures
     * 'renderbuffer-X-Y'. The XML part is generated from the %resource name.
     */
    static TiXmlElement *buildTextureDescriptor(const std::string &name);

    /**
     * Builds the XML part of program %resource descriptors. The XML part is
     * generated from the %resource name of the form "shader1;shader2;shader3;...".
     */
    static TiXmlElement *buildProgramDescriptor(const std::string &name);

    /**
     * Loads the archive file of the given name.
     *
     * @param name the name of the archive file to be loaded.
     * @param[out] t returns the last modification time of this file on disk.
     * @return the archive file of the given name, or NULL if this file is not
     *      found.
     */
    TiXmlDocument *loadArchive(const std::string &name, time_t &t);

    /**
     * Loads the ASCII or binary part of a ResourceDescriptor.
     *
     * @param e the XML part of a ResourceDescriptor.
     * @param[out] size returns the size of ASCII or binary part.
     * @param[in,out] stamps the last modification time of the file(s) that
     *      contain this ASCII or binary part, or an empty vector if this ASCII
     *      or binary part has not been loaded yet. These modification times are
     *      updated by this method if they have changed. Each element of this
     *      vector contains a file name and its last modification time.
     * @return the ASCII or binary part of the given ResourceDescriptor, or NULL
     *      if this %resource has no binary part, if this part is not found, or
     *      if the last modification times are still equal to the given
     *      modification times.
     */
    unsigned char* loadData(TiXmlElement *e, unsigned int &size, std::vector< std::pair<std::string, time_t> > &stamps);

    /**
     * Loads the ASCII part of a shader %resource, i.e. the shader source code.
     *
     * @param desc the XML part of a shader ResourceDescriptor.
     * @param paths the directories where the shader source files must be looked for.
     * @param path a file containing (a part of the) shader source code.
     * @param data the content of the 'path' file.
     * @param[in,out] size the size of the content of the 'path' file and, after the
     *      method's execution, the size of the returned data.
     * @param[in,out] stamps the last modification time of the file(s) that contain
     *      the shader source code, or an empty vector if these files are not known
     *      yet. These modification times are updated by this method if they have
     *      changed. Each element of this vector contains a file name and its last
     *      modification time.
     * @throw exception if a problem occurs.
     */
    unsigned char* loadShaderData(TiXmlElement *desc, const std::vector<std::string> &paths,
            const std::string &path, unsigned char *data, unsigned int &size, std::vector< std::pair<std::string, time_t> > &stamps);

    /**
     * Loads the binary part of a texture %resource.
     *
     * @param desc the XML part of the texture %resource descriptor.
     * @param path the absolute name of the file containing the texture image.
     * @param data the encoded image data (in PNG, PJG, etc format).
     * @param[in,out] size the size of the encoded image data and, after the
     *      method's execution, the size of the returned data.
     * @param[in,out] stamps the last modification time of the file that contain the
     *      texture image, or an empty vector if this file is not loaded yet. This
     *      modification time is updated by this method if it has changed. Each
     *      element of this vector contains a file name and its last modification
     *      time.
     */
    unsigned char* loadTextureData(TiXmlElement *desc, const std::string &path,
            unsigned char *data, unsigned int &size, std::vector< std::pair<std::string, time_t> > &stamps);
};

}

#endif
