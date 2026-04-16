It looks like you have a solid GNS3 topology coming together! [cite_start]Milestone 2 is all about exposing your internal web servers securely to the outside world[cite: 139]. [cite_start]Because reverse proxies are frequently targeted by malicious actors[cite: 148], proving your implementation requires testing both the connectivity and the specific Web Application Firewall (WAF) hardening features you were asked to configure.

Here is a comprehensive guide on the commands you can use during your 10-minute demo to prove each requirement of Milestone 2.

> **Note on GNS3 Virtual PCs (VPCS):** Standard VPCS nodes in GNS3 only support basic commands like `ping` and `trace`. To run the `curl` and `openssl` commands below, you will need to ensure your "Remote-Employee" and "Malicious" nodes are actually lightweight Linux containers (like Alpine or Debian) rather than the default VPCS. 

Replace `<REVERSE_PROXY_IP>` with the external-facing IP address of your `debian-netsec-1` node. Run these tests from the **Remote-Employee** or **Malicious** external nodes.

---

### **1. Prove the Reverse Proxy works**
[cite_start]To prove that your reverse proxy successfully redirects packets from the Internet to the application servers[cite: 140]:

```bash
# A standard GET request should return the HTML from Server-1 or Server-2
curl -s http://<REVERSE_PROXY_IP> | grep "title"
```

### **2. Prove the WAF Hardening Features**

[cite_start]**Feature 1: Hide Server Version Information [cite: 152]**
You must prove that NGINX is not leaking its exact version number.
```bash
curl -I http://<REVERSE_PROXY_IP>
```
* **Success:** The output shows `Server: nginx`.
* **Failure:** The output shows something like `Server: nginx/1.18.0`.

[cite_start]**Feature 2: Configure Secure HTTP Headers [cite: 153]**
You must prove that security headers are being injected into the response.
```bash
curl -I http://<REVERSE_PROXY_IP>
```
* **Success:** Look for headers like `X-Frame-Options: SAMEORIGIN`, `X-Content-Type-Options: nosniff`, and `Content-Security-Policy` in the terminal output.

[cite_start]**Feature 3: Implement SSL/TLS Best Practices [cite: 154]**
You must prove that you support HTTPS and have disabled weak/deprecated protocols (like TLS 1.0 or 1.1).
```bash
# Test if a weak protocol is successfully rejected
openssl s_client -connect <REVERSE_PROXY_IP>:443 -tls1

# Test if a modern, secure protocol is accepted
openssl s_client -connect <REVERSE_PROXY_IP>:443 -tls1_2
```
* **Success:** The connection fails when forcing `-tls1`, but succeeds with `-tls1_2` or `-tls1_3`.

[cite_start]**Feature 4: Control Request Methods and Size Limits [cite: 155]**
You must prove that unwanted HTTP methods (like `TRACE` or `DELETE`) and oversized payloads are rejected.
```bash
# Test forbidden method (should return 405 Method Not Allowed or 403 Forbidden)
curl -X DELETE -I http://<REVERSE_PROXY_IP>

# Test size limit by creating a 5MB dummy file and uploading it (should return 413 Request Entity Too Large)
dd if=/dev/zero of=largefile.txt bs=1M count=5
curl -X POST -F "file=@largefile.txt" http://<REVERSE_PROXY_IP>/
```

[cite_start]**Feature 5: Implement Rate Limiting [cite: 156]**
You must prove that rapid, consecutive requests are throttled to prevent DoS attacks.
```bash
# Rapidly fire 20 requests and output only the HTTP status codes
for i in {1..20}; do curl -s -o /dev/null -w "%{http_code}\n" http://<REVERSE_PROXY_IP>/; done
```
* **Success:** The first few requests will return `200` (OK), but subsequent requests will start returning `503 Service Unavailable` or `429 Too Many Requests`.

[cite_start]**Feature 6: Secure File and Directory Access [cite: 157]**
You must prove that access to common sensitive hidden files or directories is explicitly blocked.
```bash
curl -I http://<REVERSE_PROXY_IP>/.env
curl -I http://<REVERSE_PROXY_IP>/.git/config
```
* **Success:** The server returns a `403 Forbidden` or `404 Not Found` rather than exposing the file.

[cite_start]**Feature 7: Configure Proper Logging and Monitoring [cite: 158]**
To prove this, you need to execute commands **directly on the reverse proxy node (`debian-netsec-1`)**, not from the external PCs.
```bash
# Watch the access log live while generating traffic from the Remote-Employee PC
tail -f /var/log/nginx/access.log

# Check the error logs for the blocked requests (like the rate-limiting or large file tests above)
tail -f /var/log/nginx/error.log
```

[cite_start]**Feature 8: Implement Geographic and IP-based Restrictions [cite: 159]**
To prove this, you need a specific path (e.g., `/admin`) that is restricted. 
* **From the allowed IP (e.g., Remote-Employee):**
  ```bash
  curl -I http://<REVERSE_PROXY_IP>/admin
  ```
  *(Should return `200 OK` or `401 Unauthorized` if authentication is required).*
* **From the denied IP (e.g., Malicious PC):**
  ```bash
  curl -I http://<REVERSE_PROXY_IP>/admin
  ```
  *(Should return `403 Forbidden` or `Connection Refused`).*