#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <list>
# include <map>
# include <vector>
# include <iostream>

class Location
{
	private:
		std::string location_name;
		std::string root;
		std::list<std::string> index;
		std::list<std::string> allow_methods;
		std::map<int, std::string> error_pages;
		int request_max_body_size;
		std::string upload_path;
		bool auto_index;
		std::map<std::string, std::string> cgi_infos;
		std::string auth_key;

		int redirect_return;
		std::string redirect_addr;

	public:
		Location();
		virtual ~Location();
		Location(const Location &src);
		Location& operator=(const Location &src);

		void setRoot(const std::string &root);
		void setRequestMaxBodySize(int request_max_body_size);
		void setUploadPath(const std::string &upload_path);
		void setAutoIndex(bool auto_index);
		void setCgiInfos(std::map<std::string, std::string> &cgi_infos);
		void setAuthKey(const std::string &auth_key);
		void setRedirectReturn(int redirect_return);
		void setRedirectAddr(const std::string &redirect_addr);
		void setLocationName(std::string &locaton_name);

		const std::string &getLocationName(void);
		const std::string &getRoot();
		std::list<std::string> &getIndex();
		std::list<std::string> &getAllowMethods();
		int getRequestMaxBodySize();
		const std::string &getUploadPath();
		bool getAutoIndex();
		std::map<std::string, std::string> &getCgiInfos();
		const std::string &getAuthKey();
		int getRedirectReturn();
		const std::string &getRedirectAddr();
		std::map<int, std::string> &getErrorPages();

		std::string checkAutoIndex(std::string &uri);

};

#endif