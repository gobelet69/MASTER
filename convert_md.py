import os
import markdown
from weasyprint import HTML, CSS

# --- CONFIGURATION ---
SOURCE_DIR = './'      # Replace with your source folder path
DESTINATION_DIR = './my_pdf_export'     # Replace with your destination folder path

def convert_md_to_pdf(src_path, dest_path):
    """Converts a single Markdown file to a single-page PDF using WeasyPrint."""
    try:
        # 1. Read the Markdown file
        with open(src_path, 'r', encoding='utf-8') as f:
            md_content = f.read()

        # 2. Convert Markdown to HTML
        html_body = markdown.markdown(md_content, extensions=['fenced_code', 'tables', 'sane_lists'])

        # 3. Wrap in basic HTML structure
        html_content = f"""
        <html>
        <head>
            <meta charset="utf-8">
        </head>
        <body>
            {html_body}
        </body>
        </html>
        """

        # 4. Define CSS to force a single, continuous long page
        # We set an extremely large height (5000mm) to prevent page breaks.
        css = CSS(string='''
            @page {
                size: 210mm 5000mm; /* A4 width, massive height */
                margin: 10mm;
            }
            body { 
                font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; 
                line-height: 1.6; 
                color: #333; 
            }
            code { background-color: #f4f4f4; padding: 2px 4px; border-radius: 4px; }
            pre code { display: block; padding: 10px; white-space: pre-wrap; }
            table { border-collapse: collapse; width: 100%; }
            table, th, td { border: 1px solid #ddd; padding: 8px; }
            img { max-width: 100%; height: auto; }
        ''')

        # 5. Generate the PDF
        HTML(string=html_content).write_pdf(dest_path, stylesheets=[css])
        print(f"✅ Converted: {os.path.basename(src_path)}")

    except Exception as e:
        print(f"❌ Error converting {src_path}:\n{e}")

def process_directory(source, destination):
    """Scans folders, recreates architecture, and triggers conversion."""
    if not os.path.exists(destination):
        os.makedirs(destination)

    for root, dirs, files in os.walk(source):
        rel_path = os.path.relpath(root, source)
        target_dir = os.path.join(destination, rel_path)

        if not os.path.exists(target_dir):
            os.makedirs(target_dir)

        for file in files:
            if file.lower().endswith('.md'):
                src_file = os.path.join(root, file)
                
                base_name = os.path.splitext(file)[0]
                dest_file = os.path.join(target_dir, base_name + '.pdf')
                
                convert_md_to_pdf(src_file, dest_file)

if __name__ == "__main__":
    print(f"Starting conversion from '{SOURCE_DIR}' to '{DESTINATION_DIR}'...")
    process_directory(SOURCE_DIR, DESTINATION_DIR)
    print("Done!")