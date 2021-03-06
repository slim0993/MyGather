#include "get_data.h"

void create_get_data()
{	 
	if (sc_bus_init(SC_BUS_THREADED_IOLOOP, SC_BUS_TRACE_LEVEL_WARNING, NULL) < 0)
    {
        printf( "ERROR sc_bus_init"  );
    }

    if (sc_bus_declare_name(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS) < 0)
    {
        printf(  "ERROR sc_bus_declare_name"  );
    }
}

void destroy_get_data()
{
	sc_bus_undeclare_name(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS);
	sc_bus_exit();
}

void set_method(char* mtd)
{
	method = mtd;
}

char* get_method_value_by_string()
{
	DBusMessage *msg;
	DBusMessage *reply;
	DBusMessageIter iter_base;
	char *param;
	dbus_bool_t result = FALSE;
	
	msg = dbus_message_new_method_call(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS, DIAGNOSTIC_MENU_DBUS_PATH_DBUS,DIAGNOSTIC_MENU_DBUS_INTERFACE_MONITORING, method.c_str());

	if (msg == NULL)
	{
		printf(  "dbus_message_new_method_call failed on no memory"  );
		return "";
	}
	
	if (sc_bus_method_call (msg, NULL, NULL, (void *)&reply) < 0)
	{
		printf(  "sc_bus_method_call for "  method  " failed"  );
		return "";
	}
	result = dbus_message_iter_init(reply, &iter_base);
	
	if(result == FALSE)
	{
		printf(  "dbus_message_iter_init for "  method  " failed"  );
		return "";
	}
	dbus_message_iter_get_basic(&iter_base, &param);
	dbus_message_unref (reply);
	printf(::string data(param);
	return data;
}

char* get_method_value_by_array(int length)
{
	DBusMessage *msg;
	DBusMessage *reply;
	DBusMessageIter iter_base,sub;
	char *param;
	
	msg = dbus_message_new_method_call(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS, DIAGNOSTIC_MENU_DBUS_PATH_DBUS,DIAGNOSTIC_MENU_DBUS_INTERFACE_MONITORING, method.c_str());

	if (msg == NULL)
	{
		printf(  "dbus_message_new_method_call failed on no memory"  );
		return "";
	}
	
	if (sc_bus_method_call (msg, NULL, NULL, (void *)&reply) < 0)
	{
		printf("sc_bus_method_call for "  " failed"  );
		return "";
	}
	dbus_message_iter_init(reply, &iter_base);

	if (dbus_message_iter_get_arg_type(&iter_base)==DBUS_TYPE_ARRAY)
	{
		dbus_message_iter_recurse (&iter_base, &sub);

		if (dbus_message_iter_get_arg_type(&sub)==DBUS_TYPE_BYTE)
		{
				dbus_message_iter_get_fixed_array (&sub, &param, &length);
				printf("%ss",string data(param));
				return data;
		}
	}
	return "";
}


int main(){
    //get_data get_data;
    create_get_data();
    destroy_get_data();
    return 0;
}
