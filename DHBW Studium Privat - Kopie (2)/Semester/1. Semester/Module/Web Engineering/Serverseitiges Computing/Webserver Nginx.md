### Zentrale Konfiguration

- **/etc/nginx/nginx.conf**
- Anlegen zur **Konfiguration** über **"include-Statements"**.

### Protokollierung
```nginx
access_log /var/log/nginx/access.log
error_log /var/log/nginx/error.log
```

### Root-Verzeichnis einer Webseite
```nginx
root  /var/www/<spez.Name>

index index.html
```

### nginx.conf

1. **Prozessparameter
```nginx
user www-data #Deamon User
worker_processes auto #auto: Anzahl worker = Anzahl CPU Cores
worker_rlimit_nofile 4096 #open files
worker_connections 2048 #max connections per worker
```

2. **Konfiguration der virtuellen Webbrowser**

```nginx
http {
include /etc/nginx/sites-enabled/...;
include /etc/nginx/fastcgi.conf;
}
```

#### FAST CGI

- **FAST CGI Wrapper** liest **HTTP-Request-Nachricht**
	- **schreibt HTTP-Header-Information** als **Umgebungsvariable** des **OS**.
	- **schreibt HTTP-Body in `<stdin>`** des **CGI-Prozesses**

#### Virtuelle Webserver

- **nginx-Workerprozesse unterstützen mehrere "virtuelle Webbrowser"**.
- **Virtuelle Webbrowser** besitzen:
	- spezielle **DNS-Namen** (IP-Adresse)
	- spezielle **TCP-Ports**
	- spezielle **www-root**
- Werden unter **nginx** als **Server Blocks** bezeichnet.
```nginx
/etc/nginx/sites-enabled/server1.cfg

server {
	server_name www.example.de;
	listen 3000;

	access_log /var/log/nginx/srv1.acceslog
	error_log /var/log/nginc/srv1.errorlog
	
	root /var/www/srv01
	locaton / {
		index index.html;
		/ver/www/srv01;
						index.html;
					/product;
						product.html;
					/css;
						stylesheet.css;
	}
	location /product/ {
		index product.html;
	}
}
```

#### Server-Block mit Validierung
```nginx
server {
	#Validierung
	listen 443 ssl;
	server_name www.example.de;
	ssl_certificate server_cert .cert;
	ssl_certificate_key private_key.pem;
	ssl_protocols TLSu1.3;
	...
	...
	Rest bleibt gleich
}
```

### Reverse Proxy Eigenschaft eines Web-Server
![[Pasted image 20240221144932.png]]
```nginx
location /product/ {
	proxy_pass https://backend.example.de;
}

upstream backend.example.de {
	
}
```